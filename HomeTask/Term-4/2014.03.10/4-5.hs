add :: Ord a => a -> [a] -> [a]
add value [] = [value]
add value (x:xs) | value <= x = value : x : xs
                 | otherwise = x : (add value xs)
                 
remove :: Eq a => a -> [a] -> [a]
remove _ [] = []
remove value (x:xs) | value == x = xs
                    | otherwise = x : (remove value xs)
                    
doLoop :: [Int] -> IO()
doLoop list = do
            putStrLn("Enter a query: ")
            str <- getLine 
            case str of
                '0': _ -> putStrLn("exit")
                '1': _ -> do
                        putStrLn("Enter the value you want to add: ")
                        value <- readLn
                        doLoop (add value list)
            
                '2': _ -> do 
                        putStrLn("Enter the value you want to remove: ")
                        value <- readLn
                        doLoop (remove value list)
                '3': _ -> do 
                        putStrLn(show list)
                        doLoop list
                _      -> do 
                        putStrLn("Wrong query.")
                        doLoop list
main = do
    putStrLn("0 - exit")
    putStrLn("1 - add value to sorted list")
    putStrLn("2 - remove value from list")
    putStrLn("3 - print list")
    doLoop []
