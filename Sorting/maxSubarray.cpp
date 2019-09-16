#include<iostream>
#include<array>
#include<tuple>

template<std::size_t SIZE>
std::tuple<int, int, int> maxCrossingSubarray(std::array<int, SIZE> &A, int low, int mid, int high)
{
    int sum, leftindex, rightindex, leftsum, rightsum, i;

    leftsum=-99999999, sum=0, leftindex=mid;
    for(i=mid; i>=low; i--)
    {
        sum+=A[i];
        if(sum > leftsum)
        {
            leftsum = sum;
            leftindex = i;
        }
    }

    rightsum=-99999999, sum=0, rightindex=mid+1;
    for(i=mid+1; i<=high; i++)
    {
        sum+=A[i];
        if(sum > rightsum)
        {
            rightsum = sum;
            rightindex = i;
        }
    }

    return std::make_tuple(leftindex, rightindex, leftsum+rightsum);
}

template<std::size_t SIZE>
std::tuple<int, int, int> maxSubarray(std::array<int, SIZE> &A, int low, int high){
    if (low == high)
    {
        // std::cout << A[low] << std::endl;
        return std::make_tuple(low, high, A[low]);
    }
    else
    {
        int mid;
        mid = (low + high) / 2;

        auto leftdata = maxSubarray(A, low, mid);
        auto rightdata = maxSubarray(A, mid+1, high);
        auto data = maxCrossingSubarray(A, low, mid, high);

        if((std::get<2>(leftdata) >= std::get<2>(rightdata)) && (std::get<2>(leftdata) >= std::get<2>(data)))
            return leftdata;
        else if((std::get<2>(rightdata) >= std::get<2>(leftdata)) && (std::get<2>(rightdata) >= std::get<2>(data)))
            return rightdata;
        else 
            return data;
    }
} 


int main()
{
    std::array<int, 16> A;
    A = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    
    // int index1, index2, maxsum;
    // std::cout << "Size of array: " << A.size();

    auto data = maxSubarray(A, 0, A.size()-1);
    // index1, index2, maxsum = std::get<0>(data), std::get<1>(data), std::get<2>(data);
    std::cout << typeid(std::get<0>(data)).name() <<std::endl;

    std::cout << "Indexes of maximum subarray: " << std::get<0>(data) << "," << std::get<1>(data) << std::endl;
    std::cout << "Maximum sum: " << std::get<2>(data) << std::endl;
    return 0;
}