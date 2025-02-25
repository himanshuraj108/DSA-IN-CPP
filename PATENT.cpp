<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Code Debugger Tool</title>
    <style>
     body {
    font-family: 'Poppins', sans-serif;
    background-color: #f4f4f9;
    margin: 0;
    padding: 0;
    display: flex;
    justify-content: center;
    align-items: center;
    flex-direction: column;
}

.container {
    width: 80%;
    max-width: 800px;
    margin-top: 40px;
    padding: 20px;
    background-color: white;
    border-radius: 10px;
    box-shadow: 0 4px 10px rgba(0, 0, 0, 0.1);
    text-align: center;
}

h1 {
    color: #333;
}

select, textarea, button, input {
    width: 100%;
    padding: 12px;
    margin: 10px 0;
    border-radius: 6px;
    border: 1px solid #ccc;
    font-size: 16px;
    transition: all 0.3s ease;
}

select {
    background-color: #fff;
    cursor: pointer;
}

textarea {
    height: 200px;
    font-family: monospace;
    background-color: #f9f9f9;
    resize: vertical;
}

#runBtn {
    background-color: blue;
    color: white;
    font-size: 18px;
    font-weight: bold;
    cursor: pointer;
    border: none;
    transition: 0.3s;
}

button:hover {
    background-color: #45a049;
    transform: scale(1.05);
}

#output {
    margin-top: 20px;
    padding: 15px;
    border-radius: 6px;
    border: 1px solid #ddd;
    white-space: pre-wrap;
    font-family: monospace;
    word-wrap: break-word;
    text-align: left;
    max-height: 300px;
    overflow: auto;
    color: white; /* Default text color */
}

.success {
    background-color: #4CAF50; /* Green for success */
    color: white;
}

.error {
    background-color: #f44336; /* Red for errors */
    color: white;
}

    </style>
</head>
<body>
    <div class="container">
        <h1>Code Debugger Tool</h1>
        <select id="language">
            <option value="python">Python</option>
            <option value="cpp">C++</option>
            <option value="java">Java</option>
            <option value="c">C</option>
        </select>

        <textarea id="code" placeholder="Write your code here..."></textarea>
        


        <button id="runBtn">Debug Code</button>

        <div id="output"></div>
    </div>

    <script>
       document.getElementById('runBtn').addEventListener('click', function() {
    const code = document.getElementById('code').value;
    const language = document.getElementById('language').value;

    const data = { code: code, language: language };

    fetch('http://127.0.0.1:5000/debug', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(data)
    })
    .then(response => response.json())
    .then(result => {
        let outputElement = document.getElementById('output');

        // Extracting the 'output' key value
        let output = result.output ? result.output : "No output";

        // Format the output as required
        let formattedOutput = `OUTPUT: ${output}`;

        // Conditionally applying class based on error or success
        if (result.error) {
            outputElement.classList.remove('success');
            outputElement.classList.add('error');
            outputElement.innerHTML = `<pre>${formattedOutput}</pre>`;
        } else {
            outputElement.classList.remove('error');
            outputElement.classList.add('success');
            outputElement.innerHTML = `<pre>${formattedOutput}</pre>`;
        }
    })
    .catch(error => {
        let outputElement = document.getElementById('output');
        outputElement.classList.remove('success');
        outputElement.classList.add('error');
        outputElement.innerHTML = `<pre>Error: ${error}</pre>`;
    });
});

    </script>
</body>
</html>



import subprocess
import tempfile
import os
from flask import Flask, request, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # Enable CORS for all routes

@app.route('/debug', methods=['POST'])
def debug_code():
    data = request.get_json()
    code = data.get('code')
    language = data.get('language')

    if language == 'python':
        return execute_python(code)
    elif language == 'cpp':
        return execute_cpp(code)
    elif language == 'java':
        return execute_java(code)
    elif language == 'c':
        return execute_c(code)
    else:
        return jsonify({"error": "Unsupported language"}), 400

# Handle OPTIONS request for CORS pre-flight
@app.route('/debug', methods=['OPTIONS'])
def handle_options():
    response = jsonify({'message': 'CORS preflight request'})
    response.headers.add('Access-Control-Allow-Origin', '*')
    response.headers.add('Access-Control-Allow-Methods', 'POST, OPTIONS')
    response.headers.add('Access-Control-Allow-Headers', 'Content-Type')
    return response

# Function to execute Python code
def execute_python(code):
    try:
        # Create a temporary file to store the Python code
        with tempfile.NamedTemporaryFile(suffix='.py', delete=False) as temp_file:
            temp_file.write(code.encode())
            temp_file.close()

            # Execute the Python file
            result = subprocess.run(['python', temp_file.name], capture_output=True, text=True)

            # Remove the temporary file after execution
            os.remove(temp_file.name)

            if result.returncode == 0:
                return jsonify({"output": result.stdout})
            else:
                return jsonify({"error": result.stderr}), 500
    except Exception as e:
        return jsonify({"error": str(e)}), 500

# Function to execute C++ code
def execute_cpp(code):
    try:
        # Create a temporary file to store the C++ code
        with tempfile.NamedTemporaryFile(suffix='.cpp', delete=False) as temp_file:
            temp_file.write(code.encode())
            temp_file.close()

            # Compile the C++ file using g++
            exe_file = temp_file.name.replace('.cpp', '.exe')
            compile_result = subprocess.run(['g++', temp_file.name, '-o', exe_file], capture_output=True, text=True)

            if compile_result.returncode != 0:
                os.remove(temp_file.name)
                return jsonify({"error": compile_result.stderr}), 500

            # Run the compiled C++ program
            run_result = subprocess.run([exe_file], capture_output=True, text=True)

            # Clean up the temporary files
            os.remove(temp_file.name)
            os.remove(exe_file)

            if run_result.returncode == 0:
                return jsonify({"output": run_result.stdout})
            else:
                return jsonify({"error": run_result.stderr}), 500
    except Exception as e:
        return jsonify({"error": str(e)}), 500

# Function to execute Java code
# Function to execute Java code
def execute_java(code):
    try:
        # Create a temporary file to store the Java code
        with tempfile.NamedTemporaryFile(suffix='.java', delete=False) as temp_file:
            temp_file.write(code.encode())
            temp_file.close()

            # Extract the class name from the code (assuming class is public)
            class_name = None
            with open(temp_file.name, 'r') as f:
                lines = f.readlines()
                for line in lines:
                    if 'public class' in line:
                        class_name = line.split()[2]
                        break

            if class_name is None:
                return jsonify({"error": "No public class found in the code."}), 400

            # Rename the file to match the class name
            renamed_file = f"{os.path.dirname(temp_file.name)}\\{class_name}.java"
            os.rename(temp_file.name, renamed_file)

            # Compile the Java file using javac
            compile_result = subprocess.run(['javac', renamed_file], capture_output=True, text=True)

            if compile_result.returncode != 0:
                os.remove(renamed_file)
                return jsonify({"error": compile_result.stderr}), 500

            # Run the Java program using java
            run_result = subprocess.run(['java', class_name], cwd=os.path.dirname(renamed_file), capture_output=True, text=True)

            # Clean up the temporary files
            os.remove(renamed_file)

            if run_result.returncode == 0:
                return jsonify({"output": run_result.stdout})
            else:
                return jsonify({"error": run_result.stderr}), 500
    except Exception as e:
        return jsonify({"error": str(e)}), 500
    

def execute_c(code):
    try:
        # Create a temporary file to store the C++ code
        with tempfile.NamedTemporaryFile(suffix='.c', delete=False) as temp_file:
            temp_file.write(code.encode())
            temp_file.close()

            # Compile the C++ file using g++
            exe_file = temp_file.name.replace('.c', '.exe')
            compile_result = subprocess.run(['g++', temp_file.name, '-o', exe_file], capture_output=True, text=True)

            if compile_result.returncode != 0:
                os.remove(temp_file.name)
                return jsonify({"error": compile_result.stderr}), 500

            # Run the compiled C++ program
            run_result = subprocess.run([exe_file], capture_output=True, text=True)

            # Clean up the temporary files
            os.remove(temp_file.name)
            os.remove(exe_file)

            if run_result.returncode == 0:
                return jsonify({"output": run_result.stdout})
            else:
                return jsonify({"error": run_result.stderr}), 500
    except Exception as e:
        return jsonify({"error": str(e)}), 500


if __name__ == '__main__':
    app.run(debug=True)