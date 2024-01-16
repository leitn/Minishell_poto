import subprocess

# Lecture des commandes à partir du fichier
with open("cmd_2.txt", "r") as file:
    shell_commands = file.read().splitlines()

# Fonction pour exécuter le script C sur une commande shell
def tokenize_command(command):
    process = subprocess.Popen(["./minishell", command], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    output, error = process.communicate()
    return output.split('\n')

# Fonction pour afficher les tokens de chaque commande
def display_tokens(command, tokens):
    print(f"Commande : {command}")
    print("Tokens :")
    for token in tokens:
        print(f"  - {token}")
    print("=" * 30)

# Application du script C sur chaque commande et affichage des tokens
for command in shell_commands:
    tokens = tokenize_command(command)
    if tokens and tokens[-1] == '':
        tokens.pop()
    print(tokens)
    display_tokens(command, tokens)

