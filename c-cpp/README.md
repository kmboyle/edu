# The idea is to create dev environments using nix flakes to install dependencies

Template:
<https://github.com/the-nix-way/dev-templates/tree/main/c-cpp>

At the root of your repository (or directory), Direnv can start by allowing the recently-created .envrc file to execute:

```bash
direnv allow .
```

Once Direnv detects that the current working directory is no longer inside the repository with a .envrc file, it will automatically unload the environment:

```bash
cd ..
```

more information here: <https://wiki.nixos.org/wiki/Direnv>
