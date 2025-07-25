    }
                load = 0;
            }
            load += a[i];
        }
        return days;
        int days = 1, load = 0;
        for(int i = 0; i < a.size(); i++){
            if(load + a[i] > cap){
                days++;