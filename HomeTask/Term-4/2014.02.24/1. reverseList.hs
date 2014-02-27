reverse0 :: [a] -> [a]
reverse1 :: [a] -> [a] -> [a]
reverse0 xs = reverse1 [] xs
reverse1 xs [] = xs
reverse1 xs1 (x:xs2) = reverse1 (x:xs1) xs2