//package org.example;


import java.math.BigInteger;
import java.util.*;
import java.io.*;

import static java.lang.System.*;


public class Main {
    public static void main(String[] args) throws IOException {
        HashMap<Integer,Integer> mp = new HashMap<>();
        Integer n = 500;
        for(int i=1;i<=n;i++){
            int p = i;
            while (p%5==0){
                mp.put(5,mp.getOrDefault(5,0)+1);
                p/=5;
            }
        }
        out.println(mp.get(5));
        InputStreamReader inputStreamReader = new InputStreamReader(in);
        BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
        int num = Integer.parseInt(bufferedReader.readLine());
        int[] parr = Arrays.stream(bufferedReader.readLine().strip().split(" ")).mapToInt(Integer::parseInt).toArray();
        parr = Arrays.stream(parr).sorted().toArray();
        for (int i : parr) {
            out.println(i);
        }
        out.println(n.getClass());
    }
}



class BIT{
    private final Integer[] arr;
    int size ;
    public BIT(int n){
        arr = new Integer[n+1];
        size = n+1;
        Arrays.fill(arr,0);
    }
    public void update(int idx,int val){
        while(idx < size){
            arr[idx]+=val;
            idx += (idx&-idx);
        }
    }
    public Integer query(int idx){
        int sum = 0;
        while(idx>0){
            sum+= arr[idx];
            idx -= (idx&-idx);
        }
        return sum;
    }
    public Integer queryRange(int left,int right){
        return this.query(right) - this.query(left-1);
    }
}

class SegmentTree {
    private final Integer[] tree;
    private final int n ;
    public SegmentTree(Integer[] arr){
         this.tree = new Integer[arr.length * 4];
         this.n = arr.length;
         this.build(arr,1,0,n-1);
    }

    public void display(){
        for(Integer i : tree){
            out.print(String.valueOf(i)+" ");
        }
    }
    private void build(Integer[] arr,int node,int left,int right){
        if(left == right){
            this.tree[node] = arr[left];
            return ;
        }
        int mid = (left+right)/2;
        build(arr,node*2,left,mid);
        build(arr,node*2+1,mid+1,right);
        this.tree[node] = this.tree[node*2] + this.tree[node*2+1];
    }
    private void updatePoint(int node,int left,int right,int idx,Integer val){
        if(left==right){
            this.tree[node] = val;
            return ;
        }
        int mid = (left+right)/2;
        if(idx<=mid)updatePoint(node*2,left,mid,idx,val);
        else updatePoint(node*2+1,mid+1,right,idx,val);
        this.tree[node] = this.tree[node*2]+this.tree[node*2+1];
    }

    public void updatePoint(int idx,Integer val){
        this.updatePoint(1,0,n-1,idx,val);
    }

    private Integer queryRange(int node,int left,int right,int start,int end){
        if(left>end || right<start)return 0;
        if(left>=start && right<=end){
            return this.tree[node];
        }
        int mid = (left+right)/2;
        Integer leftSum = queryRange(node*2,left,mid,start,end) ;
        Integer rightSum = queryRange(node*2+1,mid+1,right,start,end);
        return leftSum+rightSum;
    }
    public Integer queryRange(int start,int end){
        return queryRange(1,0,n-1,start,end);
    }
}

class SparseTable {
    private final Integer[][] sparseTable;
    int n,k;
    public SparseTable(Integer[] arr){
        this.n = arr.length;
        this.k = (int)(Math.log10(n)/Math.log10(2))+1;
        sparseTable = new Integer[n][k];
        for (int i = 0; i < n; ++i)
            sparseTable[i][0] = arr[i];

        for (int j = 1; j < k; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                sparseTable[i][j] = sparseTable[i][j - 1] + sparseTable[i + (1 << (j - 1))][j - 1];
            }
        }


    }
    Integer query(int L,int R){
        Integer sum = 0;
        while (L <= R) {
            int j = (int)(Math.log10(R - L + 1)/Math.log10(2));
            sum += sparseTable[L][j];
            L += (1 << j);
        }
        return sum;
    }
}