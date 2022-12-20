void prostewybieranie(vector<int> a) {
    for (int i=0;i< n;i++)
    {
        k=i;
        x=a[i]; //szukamy elementu minimalnego w ciągu a[i]...a[n]
        for (int j=i+1;j<n;j++) {
            if (a[j]<x)
            {
                k=j;
                x=a[j]
            }
        }        
        a[k] = a[i];
        a[i] = x; //zamieniamy element i-ty z min
    }
    return a;
}

int void(){
    auto vect = new Vector<int>();
    vect.push_back(2);
    vect = prostewybieranie(a); 
}