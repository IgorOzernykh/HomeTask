data Tree a = Nil
			| Node (Tree a) a (Tree a)

height :: Tree a -> Int
height Nil = 0
height (Node leftChild _ rightChild) = 1 + max (height leftChild) (height rightChild)

heightMin :: Tree a -> Int
heightMin Nil = 0
heightMin (Node leftChild _ rightChild) = 1 + min (heightMin leftChild) (heightMin rightChild)

--			 15
--		   /    \
--		 10      27
--		/  \    /  \
--	   7   12  22  30
--	  /	  /  \     / \
--	 4	 11  13   35  47
--	/ \
-- 3   6
--	  /
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
									47
									Nil
								)
								30
								(Node
									Nil
									35
									Nil
								)
							)
						)
					)
                    
        putStrLn "Tree height: "
        putStrLn (show $ height tree)
        putStrLn "Min subtree height: "
        putStrLn (show $ heightMin tree)