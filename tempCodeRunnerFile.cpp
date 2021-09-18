    int num;
    cin>>num;
    int *a = new int[num];
    for(int i = 0; i<num; i++) 
        cin>>a[i];
    selectionSort(a, num);
    for(int i = 0; i<num; i++) 
        cout<<a[i]<<endl;
    return 0;
