(ns fungp.vtest2
  (:use fungp.core)
  (:use fungp.util)
  (:use clojure.pprint))

(def criteria 0.01)

(def sample-functions
  '[[+ 2]
    [- 2]
    [* 2]
    [fungp.util/sdiv 2]
    [fungp.util/sin 1]])

(def sample-parameters
    ['x 'y])

(def number-literals
  (map float (range 10)))

(def in-list1 '(-13 -12 -11 -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 9 10 11 12))
(def in-list2 '(-26 -24 -22 -20 -18 -16 -14 -12 -10 -8 -6 -4 -2 0 2 4 6 8 10 12 14 16 18 20 22 24 ))
; sinc(sqrt(x^2-xy+x+y^2-y))
; (def out-list '(-0.0019188370756 -0.00193712789275 -0.000400820891594 0.00274479899566 0.00247227067859 -0.00436648648607 -0.000402080112052 0.00688579288317 -0.012423608174 0.0189736075392 -0.0329343874698 0.0707576682639 -0.189200623827 0.454648713413 -0.0544021110889 -0.0377324317503 0.000402316479668 0.0110555811651 0.00975320383685 0.00700171185315 0.00530752382223 0.0042684473983 0.00285119184111 0.000400993893976 -0.00196859934359 ))

; e^(-(x^2+y^2)*3) + sin(10(x^2+y^2))/10
; (def out-list '(-0.0773432295122 -0.050584566822 -0.0649898449673 -0.0987966438767 -0.0468038214714 0.0958847282056 -0.0427991971445 0.0132202352756 -0.0346536351996 0.0893969648197 -0.0683283725036 -0.0873297297214 -0.0262371794681 1.0 -0.0262371794681 -0.0873297297214 -0.0683283725036 0.0893969648197 -0.0346536351996 0.0132202352756 -0.0427991971445 0.0958847282056 -0.0468038214714 -0.0987966438767 -0.0649898449673 -0.050584566822 ))

; x* sin(sqrt(x^2+y^2)) + xy
; (def out-list '(347.276127667 276.100137497 247.617649885 203.611783171 153.390720587 134.558172873 97.6117873018 67.4921700635 54.9148967035 30.1510880766 16.7629867498 9.94255559792 1.21325086845 0.0 2.78674913155 6.05744440208 19.2370132502 33.8489119234 45.0851032965 76.5078299365 98.3882126982 121.441827127 170.609279413 196.388216829 236.382350115 299.899862503 ))

; x/2*sin(x) +  y/2*sin(y)
(def out-list '(12.854429114 -14.0863778521 -6.0973056415 6.40934695283 -4.69829279474 1.65420645317 9.56219788474 -4.0576840026 -5.59687837844 2.44382799588 -0.556006478477 -0.60430756379 1.75076841163 0.0 0.909297426826 -0.60430756379 -0.697126486537 2.44382799588 -4.63795410377 -4.0576840026 8.90521128602 1.65420645317 -5.11041127998 6.40934695283 -5.09731543495 -14.0863778521 ))


(defn sample-fitness
  [tree]
  (try
    (let [f (compile-tree tree sample-parameters)
          results (map f in-list1 in-list2)]
      (let [r (reduce + (map off-by-sq out-list results))]
         (if (< r criteria) 0 r)))
    (catch Exception e (println e) (println tree))))

(defn sample-report
  [tree fitness]
  (pprint tree)
  (println (str "Error:\t" fitness "\n"))
  (flush))

(defn test-regression2
  [n1 n2]
  (println "\nfungp :: Functional Genetic Programming in Clojure")
  (println "Mike Vollmer, 2012")
  (println (str "Test inputs: " (vec in-list1)))
  (println (str "Test inputs: " (vec in-list2)))
  (println (str "Test outputs: " (vec out-list)))
  (println (str "Max generations: " (* n1 n2)))
  (println)
  (let [options {:iterations n1
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
        [tree score] (rest (run-genetic-programming options))]
    (do (println "Done!")
        (sample-report tree score))))
