getMinA a b = if a > b then b else a
getMaxA a b = if a > b then a else b

getMinB a b = minimum [a, b]
getMaxB a b = maximum [a, b]
