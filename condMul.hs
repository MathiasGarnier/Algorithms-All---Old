double x  = x * 2

condMul x = if x >= 100 then double (-x) - (-x) else double x

condMul 100
-100
