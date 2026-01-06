{
  pkgs ? import <nixpkgs> { },
}:

let
  sample-app-cpp =
    let
      # Download from GitHub:
      defaultNix = builtins.fetchurl {
        url = "https://github.com/kmboyle/edu/blob/main/cpp/nix-pkg-cpp/sample-app-cpp/default.nix";
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
        sha256 = "yFaWRusBfRWs7HwveAXxRs6YcmeIY7MON0az/oATp7k=";
      };
      subdir = "cpp/nix-pkg-cpp/sample-app-cpp/src";

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
