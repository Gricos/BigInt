cin >> n >> b >> r;
    aux[n-1] = 1; BigInt numar(aux, n);
    rest = numar % b;
    if(rest == r)
        cout << numar;
    else if (rest < r){
        BigInt adun(r - rest);
        numar = numar + adun;
        cout << numar;
    }
    else {
        BigInt adun(b - (rest - r));
        numar = numar + adun;
        cout << numar;
    }
