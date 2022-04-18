if [[ $# -ne 1 ]]; then
    echo "Run this with name of lab directory (example: bash prati_vjezbe.sh lv01)"
    exit 1
fi

cd $1 || exit 1
files=(*.js)

for file in "${files[@]}"; do
    cat $file
    echo -e "\n"
    read -p "Confirm to run:"
    node $file
    echo -e "\n"
    read -p "Confirm for next file:"
done

cd ..
