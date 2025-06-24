# 24u.cz - testovací úloha

Cílem úlohy bylo získat z MP3 souboru dvě informace: název skladby a přiložený obrázek. Název skladby je vypisován na standardní výstup, obrázek pak do souboru pojmenovaného ve formátu "\<interpret\> - \<skladba\>.<typ obrázku>". (Program aktuálně řeší mimetype `image/png` a `image/jpeg`, pokud by byl z nějakého důvodu mimetype jiný, soubor by zůstal bez přípony.)
Pro úkol jsem zvolil knihovnu taglib, protože to byl upřímně řečeno první výsledek na duckduckgo - nicméně její podpora různých formátů souborů dává potenciál program rozšířit o, inu, tyto formáty. Úloha byla zpracována na OS Arch Linux a kompilována pomocí GCC 15.1.1.
### Kompilace: 
`g++ -ltag -o testUlohaCvach main.cpp`
### Omezení:
* zadaný soubor musí existovat
* pro správnou funkci programu musí zadaný soubor mít ID3 tag (minimálně interpreta a název skladby) a aspoň jeden vložený obrázek

### Co by se dalo rozšířit:
* získávat z MP3 souboru všechny přiložené obrázky (aktuálně program získává pouze první)
* přidat podporu dalších formátů
* lepší ošetření podmínek (neexistence souboru, absence informací v ID3 tagu, absence vloženého obrázku)