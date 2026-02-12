let
  x = 1;
  y = 2;
in
{
  inherit x y;
}
# { x = 1; y = 2; }
# The fragment
# inherit x y;
# is equivalent to
# x = x; y = y;
# let
#   a = { x = 1; y = 2; };
# in
# {
#   inherit (a) x y;
# }
# { x = 1; y = 2; }
