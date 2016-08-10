var
	n,i,j,k:longint;
	ans,aa,ab,t:int64;
	a,b,tb,pos,home:array[0..4000]of longint;
	arr:array[0..4000]of longint;
	
	function lowbit(x:longint):longint;
	begin
		exit(x and (-x));
	end;
	
	function get(x:longint):longint;
	var
		ans:longint;
	begin
		ans:=0;
		while x>0 do begin
			ans:=ans+arr[x];
			x:=x-lowbit(x);
		end;
		exit(ans);
	end;
	
	procedure add(x:longint);
	begin
		while x<=n do begin
			inc(arr[x]);
			x:=x+lowbit(x);
		end;
	end;
	
	procedure swap(var a,b:longint);
	var
		t:longint;
	begin
		t:=a;
		a:=b;
		b:=t;
	end;

	procedure qsort;

    procedure sort(l,r: longint);
      var
         i,j,y: longint;
		 x:longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]>x do
            inc(i);
           while x>a[j] do
            dec(j);
           if not(i>j) then
             begin
                swap(a[i],a[j]);
                swap(b[i],b[j]);
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
       sort(1,n);
    end;
	
	procedure qsort2;

    procedure sort(l,r: longint);
      var
         i,j,y: longint;
		 x:longint;
      begin
         i:=l;
         j:=r;
         x:=tb[(l+r) div 2];
         repeat
           while tb[i]>x do
            inc(i);
           while x>tb[j] do
            dec(j);
           if not(i>j) then
             begin
                swap(tb[i],tb[j]);
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
       sort(1,n);
    end;
	
begin
	readln(n);
	for i:=1 to n do readln(a[i],b[i]);
	for i:=1 to n do if a[i]<b[i] then swap(a[i],b[i]);
	qsort;
	tb:=b;
	for i:=1 to n do pos[i]:=i;
	qsort2;
	tb[0]:=-1;
	fillchar(home,sizeof(home),0);
	for i:=1 to n do if tb[i]=tb[i-1] then begin
		home[pos[i]]:=home[pos[i-1]];
	end else home[pos[i]]:=i;
	ans:=0;
	for i:=1 to n do begin
		add(home[i]);
		for j:=1 to i do begin
			t:=int64(a[i])*b[j]*get(home[j]);
			if t>ans then begin
				ans:=t;
				aa:=a[i];
				ab:=b[j];
			end;
		end;
	end;
	writeln(ans);
	writeln(aa,' ',ab);
end.
