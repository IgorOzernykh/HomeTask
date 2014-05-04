data Tree a = Nil
            | Node (Tree a) a (Tree a)
            deriving (Eq)

add :: Ord a => a -> Tree a -> Tree a   
add x Nil = Node Nil x Nil
add x (Node leftChild a rightChild) | x < a = add x leftChild
                                    | x > a = add x rightChild
                                    | otherwise = error "Element already exists"

isExist :: Ord a => a -> Tree a -> Bool
isExist _ Nil = False
isExist x (Node leftChild a rightChild) | x == a = True
                                        | x < a = isExist x leftChild
                                        | otherwise = isExist x rightChild

remove :: Ord a => a -> Tree a -> Tree a
remove _ Nil = Nil
remove x (Node leftChild a rightChild) | x < a = Node (remove x leftChild) a rightChild 
                                       | x > a = Node leftChild a (remove x rightChild)
                                       | otherwise = helper
        where helper | (leftChild == Nil) && (rightChild == Nil) = Nil
                     | (leftChild == Nil) && (rightChild /= Nil) = rightChild
                     | (leftChild /= Nil) && (rightChild == Nil) = leftChild
                     | otherwise = Node (remove (rightmostChild leftChild) leftChild) (rightmostChild leftChild) rightChild
                            where rightmostChild (Node _ a rightChild) | rightChild /= Nil = rightmostChild rightChild
                                                                       | otherwise = a

height :: Tree a -> Int
height Nil = 0
height (Node leftChild _ rightChild) = 1 + max (height leftChild) (height rightChild)

size :: Tree a -> Int
size Nil = 0
size (Node leftChild _ rightChild) = 1 + size leftChild + size rightChild


--           15
--         /    \
--       10      27
--      /  \    /  \
--     7   12  22  30
--    /   /  \     / \
--   4   11  13   35  47
--  / \
-- 3   6
--    /
--   5

main = do
        let tree = 
                    (Node
                        (Node
                            (Node
                                (Node
                                    (Node
                                        Nil
                                        3
                                        Nil
                                    )
                                    4
                                    (Node
                                        (Node
                                            Nil
                                            5
                                            Nil
                                        )
                                        6
                                        Nil
                                    )
                                )
                                7
                                Nil
                            )
                            10
                            (Node
                                (Node
                                    Nil
                                    11
                                    Nil
                                )
                                12
                                (Node
                                    Nil
                                    13
                                    Nil
                                )
                            )
                        )
                        15
                        (Node
                            (Node
                                Nil
                                22
                                Nil
                            )
                            27
                            (Node
                                (Node
                                    Nil
                                    35
                                    Nil
                                )
                                30
                                (Node
                                    Nil
                                    47
                                    Nil
                                )
                            )
                        )
                    )
        putStr ("tree size: ")        
        putStrLn (show $ size tree)
        putStr ("tree height: ")   
        putStrLn (show $ height tree)
        
        putStr ("isExist 5: ")
        putStrLn (show $ isExist 5 tree)
        putStr ("isExist 8: ")
        putStrLn (show $ isExist 8 tree)
        putStr ("isExist 8(added 8): ")
        putStrLn (show $ isExist 8 (add 8 tree))
        
        putStr ("isExist 15: ")
        putStrLn (show $ isExist 15 tree)
        putStr ("isExist 15(removed 15): ")
        putStrLn (show $ isExist 15 (remove 15 tree))
