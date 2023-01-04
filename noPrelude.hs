{-# LANGUAGE NoImplicitPrelude #-}
--import GHC.Show
-- on a plus accès à rien, pas même l'addition ou autre
-- https://hackage.haskell.org/package/base-4.14.0.0/docs/src/GHC.Num.html#Num
-- https://hackage.haskell.org/package/base-4.14.0.0/docs/src/GHC.Base.html

--data PetitNombres = Un | Deux | Trois
--data Chose = False | True | Ohlala

--autrechose :: PetitNombres -> Chose
--autrechose x = False

-- besoin de http://hackage.haskell.org/package/base-4.14.0.0/docs/src/GHC.Show.html

-- faire un dossier avec les imports qu'on autorise pour la bibliothèque comme 
-- GHC.Show ou des choses vraiment élémentaires MAIS LE MOINS POSSIBLE
-- System.IO.print etc...
-- :set -v

{-|
*** Chasing dependencies:
Chasing modules from: *noPrelude.hs
!!! Chasing dependencies: finished in 0.00 milliseconds, allocated 1.008 megabyt
es
Stable obj: {}
Stable BCO: {Main}
unload: retaining objs []
unload: retaining bcos []
Ready for upsweep
  [NONREC
      ModSummary {
         ms_hs_date = 2020-05-16 15:07:22.1167509 UTC
         ms_mod = Main,
         ms_textual_imps = []
         ms_srcimps = []
      }]
*** Deleting temp files:
Deleting:
Upsweep completely successful.
*** Deleting temp files:
Deleting:
Ok, one module loaded.
-}

{-|
*** Chasing dependencies:
Chasing modules from: *noPrelude.hs
!!! Chasing dependencies: finished in 0.00 milliseconds, allocated 1.571 megabyt
es
Stable obj: {}
Stable BCO: {}
unload: retaining objs []
unload: retaining bcos []
Ready for upsweep
  [NONREC
      ModSummary {
         ms_hs_date = 2020-05-16 15:09:20.0964025 UTC
         ms_mod = Main,
         ms_textual_imps = []
         ms_srcimps = []
      }]
*** Deleting temp files:
Deleting:
compile: input file noPrelude.hs
*** Checking old interface for Main (use -ddump-hi-diffs for more details):
[1 of 1] Compiling Main             ( noPrelude.hs, interpreted )
*** Parser [Main]:
!!! Parser [Main]: finished in 0.00 milliseconds, allocated 0.398 megabytes
*** Renamer/typechecker [Main]:
!!! Renamer/typechecker [Main]: finished in 0.00 milliseconds, allocated 0.074 m
egabytes
*** Desugar [Main]:
Result size of Desugar (before optimization)
  = {terms: 6, types: 1, coercions: 0, joins: 0/0}
Result size of Desugar (after optimization)
  = {terms: 6, types: 1, coercions: 0, joins: 0/0}
!!! Desugar [Main]: finished in 0.00 milliseconds, allocated 0.112 megabytes
*** Simplifier [Main]:
Result size of Simplifier iteration=1
  = {terms: 14, types: 5, coercions: 0, joins: 0/0}
Result size of Simplifier
  = {terms: 14, types: 5, coercions: 0, joins: 0/0}
!!! Simplifier [Main]: finished in 0.00 milliseconds, allocated 0.169 megabytes
*** CoreTidy [Main]:
Result size of Tidy Core
  = {terms: 14, types: 5, coercions: 0, joins: 0/0}
!!! CoreTidy [Main]: finished in 0.00 milliseconds, allocated 0.082 megabytes
*** CorePrep [Main]:
Result size of CorePrep
  = {terms: 14, types: 5, coercions: 0, joins: 0/0}
!!! CorePrep [Main]: finished in 0.00 milliseconds, allocated 0.070 megabytes
*** ByteCodeGen [Main]:
!!! ByteCodeGen [Main]: finished in 0.00 milliseconds, allocated 0.046 megabytes

Upsweep completely successful.
*** Deleting temp files:
Deleting: C:\Users\Yapix\AppData\Local\Temp\ghc10372_0\ghc_3.c
Warning: deleting non-existent C:\Users\Yapix\AppData\Local\Temp\ghc10372_0\ghc_
3.c
Ok, one module loaded.
-}