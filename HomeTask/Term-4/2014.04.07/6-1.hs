data Tree a = Empty
            | Node (Tree a) a (Tree a)
 
treeToString :: Tree Char -> String
treeToString = helper ""
                where helper list Empty = 'e' : list
                      helper list (Node leftChild a rightChild) = 'n' : a : (helper (helper list rightChild) leftChild)

stringToTree :: [Char] -> Tree Char
stringToTree xs = fst (helper xs) 
    where helper ('n' : xs) = (Node leftChild (head xs) rightChild, rightRest) 
                    where (rightChild, rightRest) = helper leftRest
                          (leftChild, leftRest) = helper $ tail xs
          helper ('e' : xs) = (Empty, xs)

--           j
--         /   \
--        f       l
--      /  \    /  \
--     t   h    k   m
--    /   /  \     / \
--   b   g   i     p  o
--  / \
-- a   d
--    /
--   c

main = do
        let tree = 
                    (Node
                        (Node
                            (Node
                                (Node
                                    (Node
                                        Empty
                                        'a'
                                        Empty
                                    )
                                    'b'
                                    (Node
                                        (Node
                                            Empty
                                            'c'
                                            Empty
                                        )
                                        'd'
                                        Empty
                                    )
                                )
                                't'
                                Empty
                            )
                            'f'
                            (Node
                                (Node
                                    Empty
                                    'g'
                                    Empty
                                )
                                'h'
                                (Node
                                    Empty
                                    'i'
                                    Empty
                                )
                            )
                        )
                        'j'
                        (Node
                            (Node
                                Empty
                                'k'
                                Empty
                            )
                            'l'
                            (Node
                                (Node
                                    Empty
                                    'p'
                                    Empty
                                )
                                'm'
                                (Node
                                    Empty
                                    'o'
                                    Empty
                                )
                            )
                        )
                    )
        putStrLn(show $ treeToString tree)
        let str = "njnfntnbnaeendnceeeenhngeenieenlnkeenmnpeenoee"
        putStrLn(show $ treeToString (stringToTree str))