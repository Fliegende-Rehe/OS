mkdir Root
date && sleep 3
ls -tr / > Root/root.txt
date && sleep 3
mkdir Home
date && sleep 3
ls -tr ~ > Home/home.txt

cat Root/root.txt
cat Home/home.txt
ls Root
ls Home

