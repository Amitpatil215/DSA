#include <iostream>
using namespace std;

template <typename T>
class MapNode
{

public:
    string key;
    T value;
    MapNode *next;

    MapNode(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class myMap
{
private:
    MapNode<V> **buckets;
    int count;
    int numBuckets;

    int getBucketIndex(string key)
    {
        int hashcode = 0;
        int primeNo = 37;
        for (int i = key.size() - 1, i >= 0; i--)
        {
            hashcode += key[i] * base;
            base = base * p;

            // a base incresing exponentially and ultimately we want to compress it, by using
            // (n1,n2,n3) % k = [(n1%k)*(n2%k)*(n3%k)] % K
            hashcode = hashcode % numBuckets;
            base = base % numBuckets;
        }
        return hashcode % numBuckets; // compression function
    }

    void reHash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL;
        }
        int oldBucketSize = numBuckets;
        numBuckets *= 2;
        count = 0;
        for (int i = 0; i < oldBucketSize; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != null)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        // Deleting old buckets and currsponding linkedlist
        for (int i = 0; i < oldBucketSize; i++)
        {
            delete temp[i];
        }
        delete[] temp;
    }

public:
    myMap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~myMap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i]; // deltetinglinked list recursively
        }
        delete[] buckets; // delete array
    }

    int size()
    {
        return count;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        // checking if key is present in the linked list
        // if present then simply return the value
        while (head != NULL)
        {

            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        // checking if key is alredy present in the linked list
        // if present then simply update the value
        while (head != NULL)
        {

            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        // if key is not present then create one and insert at front of Linked list
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        head = node;
        count++;
        ///? Rehashing

        double loadFactor = 1.0 * count / numBuckets;
        if (loadFactor > 0.7)
        {
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        // checking if key is alredy present in the linked list
        // if present then delete
        MapNode<V> *prev = NULL;
        while (head->!= NULL)
        {

            if (head->key == key)
            {
                if (prev == NULL) //if key is present at head
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value; // saving value so that we can return
                head->next = NULL;     // isolation step
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};
int main()
{
    return 0;
}