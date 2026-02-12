# with allows access to attributes without repeatedly referencing their attr set
let
  a = {
    x = 1;
    y = 2;
    z = 3;
  };
in
with a;
[
  x
  y
  z
]
# [ 1 2 3 ]
# The expression
# with a; [ x y z ]
# is equivalent to
# [ a.x a.y a.z ]
# attrs made available through with are only in scope of the expression
# following the semicolon (;)
# let
#   a = {
#     x = 1;
#     y = 2;
#     z = 3;
#   };
# in
# {
#   b = with a; [ x y z ];
#   c = x;  // undefined variable 'x'
# }
