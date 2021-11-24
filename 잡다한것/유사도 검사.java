import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;


public class HW2 {
	
	static LinkedList<String> list;
	static LinkedList<String> copied_list = new LinkedList<String>();

	public static void makeSetnMap(String name, Set<LinkedList<String>> set,Map<LinkedList<String>,Integer> map, int K) throws FileNotFoundException {
		Scanner sc = new Scanner(new File(name));

		while (true) {
			list = new LinkedList<String>();
			list.addAll(copied_list);
			copied_list.clear();
			if (!sc.hasNext())
				break;
			for (int i = list.size(); i < K; i++) {
				if (sc.hasNext()) {
					list.add(sc.next());
				}
			}
			if (!set.contains(list)) {
				set.add(list);
				map.put(list,1);
			}
			else {
				map.put(list,map.get(list)+1);
			}
			copied_list.addAll(list);
			copied_list.removeFirst();
		}
		sc.close();
		
	}

	private static double JaccardSimilarity(Set<LinkedList<String>> setA,Set<LinkedList<String>> setB) {
		int union = 0, intersection = 0;

		Iterator<LinkedList<String>> it = setB.iterator();
		while (it.hasNext()) {
			LinkedList<String> ll = it.next();
			if (setA.contains(ll))
				intersection++;
		}

		union = setA.size() - intersection + setB.size();
		
		return (double)intersection/union;
	}
	
	private static double MapSimilarity(Map<LinkedList<String>,Integer> hmA, Map<LinkedList<String>,Integer> hmB) {
		int union = 0, max_freq=0,min_freq=0;
		Iterator<LinkedList<String>> it=hmB.keySet().iterator();
		while(it.hasNext()) {
			LinkedList<String> ll=it.next();
			if(hmA.keySet().contains(ll)) {
				if(hmA.get(ll).compareTo(hmB.get(ll))>0) {
					max_freq+=hmA.get(ll);
					min_freq+=hmB.get(ll);
				}
				else {
					max_freq+=hmB.get(ll);
					min_freq+=hmA.get(ll);
				}
			}
		}
		
		it=hmA.keySet().iterator();
		while(it.hasNext()) {
			LinkedList<String> ll=it.next();
			if(!(hmB.keySet().contains(ll))) {
				union+=hmA.get(ll);
			}
		}
		
		it=hmB.keySet().iterator();
		while(it.hasNext()) {
			LinkedList<String> ll=it.next();
			if(!(hmA.keySet().contains(ll))) {
				union+=hmB.get(ll);
			}
		}
		
		union+=max_freq;
		
		return (double)min_freq/union;
		
	}

	public static String ApndExtToName(String fname){
	    int pos=fname.lastIndexOf(".");
	    if(pos==-1) {//점이 없는 경우
	    	fname+=".txt";
	    }
	    else if(fname.substring(pos+1)!=""){
	    	
	    }
	    else {
	    	fname=fname.substring(0,pos)+".txt";
	    }
	    return fname;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner sc = new Scanner(System.in);
		System.out.print("두 개의 파일 이름: ");
		String fname_1 = sc.next();
		String fname_2 = sc.next();
		
		fname_1=ApndExtToName(fname_1);
		fname_2=ApndExtToName(fname_2);
		
		System.out.print("Shingle의 수: ");
		int K = sc.nextInt();
		sc.close();
		
		Set<LinkedList<String>> hsetA = new HashSet<>();
		Set<LinkedList<String>> hsetB = new HashSet<>();
		Map<LinkedList<String>,Integer> hmA=new HashMap<LinkedList<String>,Integer>();
		Map<LinkedList<String>,Integer> hmB=new HashMap<LinkedList<String>,Integer>();
		
		makeSetnMap(fname_1, hsetA,hmA, K);
		makeSetnMap(fname_2, hsetB,hmB, K);
		
		double similarity=JaccardSimilarity(hsetA,hsetB);
		System.out.println();
		System.out.println("문자열 집합을 이용한 유사도 = " + similarity);
		
		similarity=MapSimilarity(hmA,hmB);
		System.out.println("문자열 Map을 이용한 유사도 = " + similarity);
			
	}

}
