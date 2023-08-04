#include <bits/stdc++.h> 
class minHeap {
    private:
        vector<int> arr;
        int size;
    public:    
        // Constructor for the class.
        minHeap() {
            size = 0;
        }
        
        // Implement the function to heapify the heap.
        void heapify(int node) {
            while(node < size)
            {
                int smallest = node;
                int left = 2*node + 1;
                int right = 2*node + 2;

                if(left < size && arr[smallest] > arr[left])
                    smallest = left;
                if(right < size && arr[smallest] > arr[right])
                    smallest = right;
                if(smallest != node)
                {
                    swap(arr[smallest], arr[node]);
                }
                else
                {
                    break;
                }
                node = smallest;
            }
        }

        // Implement the function to insert 'val' in the heap.
        void insert(int val) {
        
        if(size < arr.size())
        {
                arr[size] = val;
                int i = size;
                while(i > 0)
                {
                    if(arr[i] < arr[(i - 1)/2])
                    {
                        swap(arr[i], arr[(i-1)/2]);
                        i = (i-1)/2;
                    }
                    else
                    {
                        break;
                    }
                }
                size++;
            }
            else
            {
                arr.push_back(val);
                int i = size;
                while(i > 0)
                {
                    if(arr[i] < arr[(i - 1)/2])
                    {
                        swap(arr[i], arr[(i-1)/2]);
                        i = (i-1)/2;
                    }
                    else
                    {
                        break;
                    }
                }
                size++;
            }
        }

        // Implement the function to remove minimum element.
        void removeMin() {

            if(size == 0)
            return;

            else if(size == 1)
            size--;

            else if(size > 1)
            {
                swap(arr[0], arr[size - 1]);
                // Heapify
                size--;
                this->heapify(0);
            }
        }

        // Implement the function to return minimum element.
        int minElement() {
            
            if(size == 0)
            return -1;

            return arr[0];
        }
};
