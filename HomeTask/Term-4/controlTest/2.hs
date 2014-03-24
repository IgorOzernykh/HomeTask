data Tree a = Nil
			| Node (Tree a) a (Tree a)

treeToList :: Tree a -> [a]
treeToList = helper []
      where helper xs Nil = xs
            helper xs (Node leftChild a rightChild) = helper (a:(helper xs leftChild)) rightChild
mList [] = []            
mList (x:xs) | x < 0 = x : (mList xs)
         | otherwise = mList xs
            
--          15
--         /    \
--       10      27
--      /  \    /  \
--     7   12  22  30
--    /   /  \     / \
--   -4   11  13   28  47
--  / \
-- -7  -2
--    /
--   -3

main = do
        let tree = (Node
                        (Node
                            (Node
                                (Node
                                    (Node
                                        Nil
                                        (-7)
                                        Nil
                                    )
                                    (-4)
                                    (Node
                                        (Node
                                            Nil
                                            (-3)
                                            Nil
                                        )
                                        (-2)
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
                                    47
                                    Nil
                                )
                                30
                                (Node
                                    Nil
                                    28
                                    Nil
                                )
                            )
                        )
                    )
        putStrLn (show $ mList (treeToList tree))