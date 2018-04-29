rm cscope.*
find /home/lizhan/myunp -name "*.c" -o -name "*.h" >> cscope.files
cscope -bq -i cscope.files
