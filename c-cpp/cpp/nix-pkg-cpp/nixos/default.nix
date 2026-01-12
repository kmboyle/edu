{
  pkgs ? import <nixpkgs> { },
}:

let
  sample-app-cpp =
    let
      # Download from GitHub:
      defaultNix = builtins.fetchurl {
        url = "https://github.com/kmboyle/edu/blob/main/c-cpp/cpp/nix-pkg-cpp/sample-app-cpp/default.nix";
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
        rev = "v1.0.0";
        sha256 = "aw2VYVkmVceEQJ0qmslbhvlTasrIKAt1yg+KlKF28L4=";
      };
      subdir = "c-cpp/cpp/nix-pkg-cpp/sample-app-cpp/src";

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
