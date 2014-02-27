reverse0 :: [a] -> [a]
reverse1 :: [a] -> [a] -> [a]
reverse0 xs = reverse1 [] xs
reverse1 xs [] = xs
reverse1 xs1 (x:xs2) = reverse1 (x:xs1) xs2

nList :: Int -> [Int]
nList 0 = []
nList 1 = [2]
nList n = head list * 2 : list 
                where list = nList (n - 1)
resList :: Int -> [Int]
resList n = reverse0 (nList n)

