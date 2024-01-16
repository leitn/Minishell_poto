import subprocess

# num_file = input("Entrez le numéro du fichier: ").replace('\r', '')
num_file = 5
with open(f"cmd_{num_file}.txt", "r") as file:
    shell_commands = file.read().splitlines()

def expander_command(command):
    print(f"Command : {command}")
    process = subprocess.Popen(["./minishell", command], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    output, error = process.communicate()
    print(f"Command expanded : {output}")
    print()

for command in shell_commands:
    expander_command(command)

