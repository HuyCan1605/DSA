for (int i = 0; i < n; ++i)
    {
        if (0 != arr[i] && count0 != 0)
        {
            for(int j = i + 1; j < n; ++j){
                if(arr[j] == 0){
                    swapElement(&arr[i], &arr[j]);
                    --count0;
                    break;
                }
            }
        }
    }