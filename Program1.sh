#*******************************************************************************
#CREATOR : JITHIN JEROME
#TITLE - FACTORIAL OF A NUMBER.
#DATE - MAY , 2022
#*******************************************************************************
echo "Enter the number :";
read a;
sum=1;
for ((i=2;i<=a;i++))
do
 sum=$((sum * i));
done

echo "Factorial of $a = $sum;"