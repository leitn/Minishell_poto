import subprocess

# Liste des commandes à tokeniser
commandes = [
    'adduser monutilisateur',
    'chown -R monutilisateur:monutilisateur /workspace/stable-diffusion-webui',
    'su - monutilisateur',
    'cd /workspace/stable-diffusion-webui',
    './webui.sh'
]

# Chemin vers l'exécutable de votre script C
chemin_executable = '/chemin/vers/votre/executable'

# Fonction pour tokeniser une commande
def tokeniser_commande(commande):
    # Appel de l'exécutable C avec la commande comme argument
    result = subprocess.run([chemin_executable, commande], capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Erreur lors de la tokenisation de la commande: {commande}")
        print(result.stderr)
    else:
        # Affichage des tokens
        print(f"Tokens pour la commande '{commande}':")
        print(result.stdout)

# Tokeniser chaque commande dans la liste
for cmd in commandes:
    tokeniser_commande(cmd)
