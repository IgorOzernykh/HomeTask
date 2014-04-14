import System.Random
import Control.Monad

list n = replicateM n (randomIO :: IO Int)