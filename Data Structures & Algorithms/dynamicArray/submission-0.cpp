class DynamicArray {
    std::unique_ptr<int[]>arr;
    int capacity {};
    int size {};
public:

    DynamicArray(int capacity): capacity(capacity) {
        arr = std::make_unique_for_overwrite<int[]>(capacity);
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (size==capacity)
            resize();
        arr[size++] = n;
    }

    int popback() {
        return arr[--size];
    }

    void resize() {
        auto newarr = std::make_unique_for_overwrite<int[]>(capacity*2);
        for (int i=0; i<capacity; ++i){
            newarr[i] = arr[i];
        }
        capacity*=2;
        arr = std::move(newarr);
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
