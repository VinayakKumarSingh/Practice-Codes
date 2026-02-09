import tkinter as tk
from tkinter import scrolledtext
import subprocess

# Set up main window
root = tk.Tk()
root.title("Shell GUI")
root.geometry("600x500")  # Increased height for additional space
root.config(bg="lightblue")  # Set background color to light blue

# Add "Welcome!" message at the top with a different font, larger size, and bold color
welcome_label = tk.Label(root, text="Welcome! to Shell implementation", font=("Arial", 20, "bold"), bg="lightblue", fg="darkblue")
welcome_label.pack(pady=10)

# Create a scrolled text box for output
output_text = scrolledtext.ScrolledText(root, width=70, height=15)
output_text.pack(padx=10, pady=10)

# Create an entry widget for command input
command_entry = tk.Entry(root, width=70)
command_entry.pack(padx=10, pady=10)

# Initialize an empty list for storing recently used commands
recent_commands = []

# Function to execute shell command
def execute_command():
    command = command_entry.get()

    # Check if the command is 'ping' with <host>, and replace <host> with 'google.com'
    if 'ping <host>' in command:
        command = command.replace('<host>', 'google.com')
    
    if command:
        output_text.insert(tk.END, f"Executing: {command}\n")
        output_text.yview(tk.END)  # Auto-scroll to the bottom

        try:
            # Execute the command and capture output
            result = subprocess.run(command, shell=True, text=True, capture_output=True)
            output_text.insert(tk.END, result.stdout)
            if result.stderr:
                output_text.insert(tk.END, result.stderr)
        except Exception as e:
            output_text.insert(tk.END, f"Error: {str(e)}\n")

        # Add the command to the recent commands list if not already present
        if command not in recent_commands:
            recent_commands.append(command)
            update_command_dropdown()

# Function to clear the output text box
def clear_screen():
    output_text.delete(1.0, tk.END)

# Function to update the dropdown with recent commands
def update_command_dropdown():
    # Clear the current options in the OptionMenu
    menu['menu'].delete(0, 'end')

    # Add commands from recent_commands to the OptionMenu
    for command in recent_commands[-10:]:  # Show only the last 10 commands
        menu['menu'].add_command(label=command, command=tk._setit(command_var, command))

# Function to handle the Enter key press
def on_enter(event):
    execute_command()

# Create the execute button
execute_button = tk.Button(root, text="Execute", command=execute_command, bg="lightgreen")
execute_button.pack(pady=5)

# Create the clear screen button
clear_button = tk.Button(root, text="Clear", command=clear_screen, bg="lightcoral")
clear_button.pack(pady=5)

# Create a label and list box for available commands
commands_label = tk.Label(root, text="Available Commands:", bg="lightblue", font=("Arial", 12))
commands_label.pack(padx=10, pady=5)

# List of example commands that can be executed
example_commands = [
    "dir          - List files and directories in the current directory",
    "echo <text>   - Print a message",
    "ipconfig     - Display network configuration",
    "cls          - Clear the terminal screen",
    "ping <host>  - Test network connectivity",
    "tasklist     - Display currently running processes",
    "systeminfo   - Display system information",
    "chkdsk       - Check disk for errors",
    "hostname     - Display the computer's name",
    "exit         - Close the command prompt",
    "mkdir <dir>  - Create a new directory",
    "del <file>   - Delete a file",
    "copy <src> <dst>  - Copy files",
    "move <src> <dst>  - Move files",
    "cls          - Clear the terminal screen"
]

# Create a listbox to display available commands
command_list = tk.Listbox(root, width=70, height=5, bg="lightgray")
command_list.pack(padx=10, pady=5)

# Insert example commands into the listbox
for command in example_commands:
    command_list.insert(tk.END, command)

# Create a label for recently used commands
recent_label = tk.Label(root, text="Recently Used Commands:", bg="lightblue", font=("Arial", 12))
recent_label.pack(padx=10, pady=5)

# Variable for storing the selected command from dropdown
command_var = tk.StringVar()

# Initialize command_var with a default value
command_var.set("Select a recent command" if not recent_commands else recent_commands[-1])

# Create a dropdown menu for recent commands
# Initialize OptionMenu with an initial command_var value
menu = tk.OptionMenu(root, command_var, "Select a recent command")
menu.pack(padx=10, pady=5)

# Function to handle selecting a command from the dropdown menu
def on_command_select(*args):
    selected_command = command_var.get()
    command_entry.delete(0, tk.END)
    command_entry.insert(tk.END, selected_command)

# Bind the command_var to the on_command_select function
command_var.trace('w', on_command_select)

# Bind Enter key to execute command
root.bind('<Return>', on_enter)

# Run the Tkinter event loop
root.mainloop()
