{
  pkgs ? import <nixpkgs> { },
}:

let
  sample-app-cpp =
    let
      # Download from GitHub:
      defaultNix = builtins.fetchurl {
        url = "https://raw.githubusercontent.com/kmboyle/edu/refs/heads/main/cpp/nix-pkg-cpp/sample-app-cpp/default.nix";
        sha256 = "sha256-nlI2hVePH56zO1BeTKNlMIXhM3R970BT70nn+rd7+bo=";
      };
      # Uncomment for local testing:
      #   defaultNix = builtins.path {
      #     path = ../sample-app-cpp;
      #   };
    in
    pkgs.callPackage defaultNix {
      # Download from GitHub:
      src = pkgs.fetchFromGitHub {
        owner = "kmboyle";
        repo = "edu";
        rev = "main"; # REPLACE WITH A TAG!
        sha256 = "VBWlF5GjoJmTFZ1QG4GTk1qNPO4FFTQLNVgAXKZscoI=";
      };
      subdir = "sample-app-cpp/src";

      # Uncomment for local testing:
      #   src = builtins.path {
      #     path = ./..;
      #   };
      #   subdir = "/sample-app-cpp";
    };
in
[
  sample-app-cpp
]
