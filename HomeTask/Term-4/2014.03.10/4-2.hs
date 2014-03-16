data Tree a = Nil
            | Node (Tree a) a (Tree a)
            
foldTree :: (a -> a -> a) -> a -> Tree a -> a
foldTree f z Nil = z
foldTree f z (Node leftChild a rightChild) = f (foldTree f a leftChild) (foldTree f z rightChild)

--           15
--         /    \
--       10      27
--      /  \    /  \
--     7   12  22  30
--    /   /  \     / \
--   4   11  13   28  47
--  / \
-- 3   6
--    /
--   5

main = do
        let tree = (Node
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
        putStrLn(show $ foldTree (+) 0 tree)