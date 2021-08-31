# NATO_Phonetic_Alphabet_Translator
It converts texts to NATO phonetic code 
(More information : https://www.nato.int/cps/en/natohq/news_150391.htm )


```cpp

  std::cout << npa::text2npa("Hello world.") ;   // Hotel Echo Lima Lima Oscar [Space] Whiskey Oscar Romeo Lima Delta Stop
  
  const auto npa_code="Hotel Echo Lima Lima Oscar [Space] Whiskey Oscar Romeo Lima Delta"
  std::cout << npa::npa2text(npa_code); //hello world
```
