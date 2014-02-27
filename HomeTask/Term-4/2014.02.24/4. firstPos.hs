firstPos :: [Int] -> Int -> Int
firstPos [] _ = error "No such element!"
firstPos (x:xs) n  = if (x == n) then 0 else (firstPos xs n) + 1