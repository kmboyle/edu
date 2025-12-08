{
  pkgs ? import <nixpkgs> { },
}:

let
  sample-app-cpp =
    let
      # Download from GitHub:
      defaultNix = builtins.fetchurl {
        url = "https://raw.githubusercontent.com/kmboyle/edu/refs/heads/main/sample-app-cpp/default.nix";
        sha256 = "0f8ms7askpvdgvd0jzhdx2flgij94xajgqy4wdjf36dd71c8k30f";
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
