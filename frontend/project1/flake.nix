{
  description = "Angular project with pnpm";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      nixpkgs,
      flake-utils,
      ...
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            git
            nodejs
            pnpm
            typescript
            typescript-language-server
            pi-coding-agent
          ];

          shellHook = ''
            echo "Entering Angular project shell with pnpm"
            export PATH="$PWD/node_modules/.bin:$PATH"
            export NODE_PATH="$PWD/node_modules\";
            echo $PATH
          '';
        };
      }
    );
}
