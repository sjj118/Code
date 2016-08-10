var
	n,m,k,i,ans:longint;
	x,y,l1,l2,t,ty,pos,home,f,max:array[0..500001]of longint;

	procedure swap(var a,b:longint);
	var
		t:longint;
	begin
		t:=a;a:=b;b:=t;
	end;
	
	procedure qsort;

    procedure sort(l,r: longint);
      var
         i,j,m,my: longint;
      begin
         i:=l;
         j:=r;
         m:=l1[(l+r) div 2];
		 my:=y[(l+r) div 2];
         repeat
           while (l1[i]>m)or((l1[i]=m)and(y[i]>my)) do
            inc(i);
           while (m>l1[j])or((l1[j]=m)and(y[j]<my)) do
            dec(j);
           if not(i>j) then
             begin
                swap(l1[i],l1[j]);
                swap(l2[i],l2[j]);
                swap(x[i],x[j]);
                swap(y[i],y[j]);
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

    begin
       sort(1,k);
    end;
	
	procedure qsort2;

    procedure sort(l,r: longint);
      var
         i,j,m,my: longint;
      begin
         i:=l;
         j:=r;
         m:=t[(l+r) div 2];
         my:=ty[(l+r) div 2];
         repeat
           while (t[i]>m)or((t[i]=m)and(ty[i]>my)) do
            inc(i);
           while (m>t[j])or((t[j]=m)and(ty[j]<my)) do
            dec(j);
           if not(i>j) then
             begin
                swap(t[i],t[j]);
                swap(ty[i],ty[j]);
                swap(pos[i],pos[j]);
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

    begin
       sort(1,k);
    end;
	
	function lowbit(x:longint):longint;
	begin
		exit(x and(-x));
	end;

	procedure put(a,x:longint);
	begin
		while a<=k do begin
			if x>max[a] then max[a]:=x;
			a:=a+lowbit(a);
		end;
	end;
	
	function get(a:longint):longint;
	begin
		get:=0;
		while a>=1 do begin
			if max[a]>get then get:=max[a];
			a:=a-lowbit(a);
		end;
	end;

begin
	readln(n,m,k);
	for i:=1 to k do readln(x[i],y[i]);
	for i:=1 to k do l1[i]:=y[i]+x[i];
	for i:=1 to k do l2[i]:=y[i]-x[i];
	qsort;
	t:=l2;
	ty:=y;
	for i:=1 to k do pos[i]:=i;
	qsort2;
	for i:=1 to k do home[pos[i]]:=i;
	for i:=1 to k do begin
		if (x[i]=x[i-1])and(y[i]=y[i-1]) then continue;
		f[i]:=get(home[i])+1;
		put(home[i],f[i]);
	end;
	for i:=1 to k do if f[i]>ans then ans:=f[i];
	writeln(m-ans);
end.
