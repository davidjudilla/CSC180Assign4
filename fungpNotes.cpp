300 iter
[options {:iterations n1
                 :migrations n2
                 :num-islands 6
                 :population-size 40
                 :tournament-size 5
                 :mutation-probability 0.1
                 :max-depth 4
                 :terminals sample-parameters
                 :numbers number-literals
                 :fitness sample-fitness
                 :functions sample-functions
                 :report sample-report }
Ouput
(let
 []
 (-
  (- (* (- x 0.0) (fungp.util/sin y)) (fungp.util/sdiv x y))
  (fungp.util/sin (* (- x 0.0) (fungp.util/sin y)))))
Error:	156.83552721449288

300
[options {:iterations n1
                 :migrations n2
                 :num-islands 10
                 :population-size 20
                 :tournament-size 5
                 :mutation-probability 0.1
                 :max-depth 4
                 :terminals sample-parameters
                 :numbers number-literals
                 :fitness sample-fitness
                 :functions sample-functions
                 :report sample-report }
Output
(let
 []
 (fungp.util/sdiv
  (fungp.util/sin y)
  (fungp.util/sin (fungp.util/sdiv y (* y x)))))
Error:	174.64280774237562




(let [options {:iterations n1
             :migrations n2
             :num-islands 10
             :population-size 20
             :tournament-size 5
             :mutation-probability 0.1
             :max-depth 10
             :terminals sample-parameters
             :numbers number-literals
             :fitness sample-fitness
             :functions sample-functions
             :report sample-report }
    [tree score] (rest (run-genetic-programming options))]
Output
(let
 []
 (fungp.util/sdiv
  (+
   (+ 0.0 0.0)
   (+
    0.0
    (+
     (+ (fungp.util/sin y) 0.0)
     (fungp.util/sin
      (+ x (fungp.util/sin (fungp.util/sin (fungp.util/sin x))))))))
  (-
   (-
    (+ 0.0 0.0)
    (fungp.util/sdiv
     (* (- 3.0 6.0) (fungp.util/sin y))
     (fungp.util/sdiv
      (-
       (fungp.util/sdiv 0.0 (fungp.util/sin y))
       (fungp.util/sdiv
        (* (- 3.0 6.0) (fungp.util/sin y))
        (fungp.util/sdiv
         (fungp.util/sdiv 3.0 y)
         (fungp.util/sin 2.0))))
      (fungp.util/sin 2.0))))
   0.0)))
Error:	4.645624221702204


  (let [options {:iterations n1
                 :migrations n2
                 :num-islands 10
                 :population-size 20
                 :tournament-size 5
                 :mutation-probability 0.1
                 :max-depth 7
                 :terminals sample-parameters
                 :numbers number-literals
                 :fitness sample-fitness
                 :functions sample-functions
                 :report sample-report }
Output

(let
 []
 (*
  (+
   (+ (fungp.util/sin (+ y (* x 0.0))) 0.0)
   (fungp.util/sin
    (+ (fungp.util/sin (fungp.util/sin (fungp.util/sin x))) 0.0)))
  x))
Error:	52.09586240537932


  (let [options {:iterations n1
                 :migrations n2
                 :num-islands 10
                 :population-size 10
                 :tournament-size 5
                 :mutation-probability 0.1
                 :max-depth 6
                 :terminals sample-parameters
                 :numbers number-literals
                 :fitness sample-fitness
                 :functions sample-functions
                 :report sample-report }
Output
(let [] (* x (fungp.util/sin y)))
Error:	174.65620070530122



(let [options {:iterations n1
             :migrations n2
             :num-islands 10
             :population-size 20
             :tournament-size 5
             :mutation-probability 0.1
             :max-depth 6
             :terminals sample-parameters
             :numbers number-literals
             :fitness sample-fitness
             :functions sample-functions
             :report sample-report }
Output
(let
 []
 (*
  (fungp.util/sin
   (+
    (fungp.util/sin (+ (fungp.util/sin x) (fungp.util/sin y)))
    (fungp.util/sin y)))
  x))
Error:	98.73309893437481


  (let [options {:iterations n1
                 :migrations n2
                 :num-islands 10
                 :population-size 20
                 :tournament-size 5
                 :mutation-probability 0.1
                 :max-depth 5
                 :terminals sample-parameters
                 :numbers number-literals
                 :fitness sample-fitness
                 :functions sample-functions
                 :report sample-report }
        [tree score] (rest (run-genetic-programming options))]
Done!
(let
 []
 (+
  (+
   (* (fungp.util/sin (fungp.util/sin x)) x)
   (* (fungp.util/sin y) x))
  (fungp.util/sin
   (+ (* (fungp.util/sin x) x) (* (fungp.util/sin y) x)))))
Error:	85.74999150168371


  (let [options {:iterations n1
                 :migrations n2
                 :num-islands 10
                 :population-size 20
                 :tournament-size 5
                 :mutation-probability 0.1
                 :max-depth 4
                 :terminals sample-parameters
                 :numbers number-literals
                 :fitness sample-fitness
                 :functions sample-functions
                 :report sample-report }
Done!
(let
 []
 (+
  (* (* x 1.0) (fungp.util/sin (fungp.util/sin x)))
  (+
   (* (* x 1.0) (fungp.util/sin y))
   (fungp.util/sin (fungp.util/sin 0.0)))))
Error:	104.60909029628952


increasing population and islands increases the computaiton time exponentially

15 20
  (let [options {:iterations n1
                 :migrations n2
                 :num-islands 20
                 :population-size 20
                 :tournament-size 5
                 :mutation-probability 0.1
                 :max-depth 6
                 :terminals sample-parameters
                 :numbers number-literals
                 :fitness sample-fitness
                 :functions sample-functions
                 :report sample-report }
        [tree score] (rest (run-genetic-programming options))]
Done!
(let
 []
 (*
  (+
   (fungp.util/sin y)
   (*
    (fungp.util/sin x)
    (*
     (fungp.util/sin (fungp.util/sin y))
     (fungp.util/sin (fungp.util/sin y)))))
  x))
Error:	91.6944984111818

40 15
  (let [options {:iterations n1
                 :migrations n2
                 :num-islands 6
                 :population-size 10
                 :tournament-size 5
                 :mutation-probability 0.1
                 :max-depth 6
                 :terminals sample-parameters
                 :numbers number-literals
                 :fitness sample-fitness
                 :functions sample-functions
                 :report sample-report }
        [tree score] (rest (run-genetic-programming options))]
(let
 []
 (fungp.util/sdiv
  (+
   (+ (fungp.util/sin x) (fungp.util/sin (+ x x)))
   (fungp.util/sin (+ x x)))
  (fungp.util/sdiv 4.0 y)))
Error:	1.6686238294316365


20 30
  (let [options {:iterations n1
                 :migrations n2
                 :num-islands 6
                 :population-size 10
                 :tournament-size 5
                 :mutation-probability 0.1
                 :max-depth 6
                 :terminals sample-parameters
                 :numbers number-literals
                 :fitness sample-fitness
                 :functions sample-functions
                 :report sample-report }
        [tree score] (rest (run-genetic-programming options))]
Done!
(let [] (* (fungp.util/sin y) x))
Error:	174.65620070530122