# Run with nix-instantiate --eval --strict rec_attr_set.nix
rec {
  one = 1;
  two = one + 1;
  three = two + 1;
}
