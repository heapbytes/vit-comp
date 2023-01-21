height=$1
row=1
until [ "$row" -gt "$height" ]; do
  spaces=$((height-row))
  star=$((2*row -1))
  until [ ! "$spaces" -gt 0 ]; do
    echo -n " "
    spaces=$((spaces-1))
  done
  until [ ! "$star" -gt 0 ]; do
    echo -n "*"
    star=$((star-1))
  done
  row=$((row+1))
  echo
done

