
# Q-193: valid phone number
# read from file.txt, only "(xxx) xxx-xxxx" or "xxx-xxx-xxxx" are considered as tellephone number
# as [\d] not work, we must use [0-9]
grep -E '^(\([0-9]{3}\)\s|[0-9]{3}-)[0-9]{3}-[0-9]{4}$' file.txt

# Q-195: 10th line
# Given a text file file.txt, print just the 10th line of the file; implement 3+ solutions
tail -n +10 file.txt | head -n 1

sed -n 10p file.txt

awk "NR==10" file.txt


# Q-192 Word frequency
# Write a bash script to calculate the frequency of each word in a text file words.txt
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r -n -k 1| awk '{ print $2, $1 }'
# tr -s, to substitute
# sort, to put same word together to facilitate following uniq
# uniq -c, remove duplicate words with counting occurrance; NOTE the numer is 1st column
# sort -r -n -k 1; sort in field1 which is of numeric in reversed order
# awk ; to switch oclumn1 and column2