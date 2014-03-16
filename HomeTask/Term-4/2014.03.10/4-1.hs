data Tree a = Nil
            | Node (Tree a) a (Tree a)
search :: (a -> Bool) -> Tree a -> [a]
search = searchHelper []
          where searchHelper xs cond Nil = xs
                searchHelper xs cond (Node leftChild a rightChild)  
                                | cond a = searchHelper (a : (searchHelper xs cond leftChild)) cond rightChild
                                | otherwise = searchHelper (searchHelper xs cond leftChild) cond rightChild 


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
        putStrLn(show $ search ((== 0). (`mod` 2)) tree)