import java.util.*;
//HashMap and Hashtable are almost identical
//Hashtable is synchronized, whereas HashMap is not. This makes HashMap better for non-threaded applications
// as unsynchronized Objects typically perform better than synchronized ones.
// Hashtable does not allow null keys or values.  HashMap allows one null key and any number of null values.
//One of HashMap's subclasses is LinkedHashMap, so in the event that you'd want predictable iteration order
//(which is insertion order by default), you could easily swap out the HashMap for a LinkedHashMap. 
//This wouldn't be as easy if you were using Hashtable.
public class HashMapDemo {
   public static void main(String args[]) {
      // Create a hash map
      HashMap hm = new HashMap();
      // HashMap(Map m) 
      // HashMap(int capacity) or HashMap(int capacity, float fillRatio)
      // Put elements to the map
      hm.put("Zara", new Double(3434.34));
      hm.put("Mahnaz", new Double(123.22));
      hm.put("Ayan", new Double(1378.00));
      hm.put("Daisy", new Double(99.22));
      hm.put("Qadir", new Double(-19.08));

      // Get a set of the entries
      Set set = hm.entrySet();
      // Get an iterator
      Iterator i = set.iterator();
      // Display elements
      while(i.hasNext()) {
         Map.Entry me = (Map.Entry)i.next();
         System.out.print(me.getKey() + ": ");
         System.out.println(me.getValue());
      }
      System.out.println();
      System.out.println("Ayan in hash is " + hm.containsKey("Ayan"));
      System.out.println("hash contains 99.22 value is " + hm.containsValue(99.22));
      // Deposit 1000 into Zara's account
      double balance = ((Double)hm.get("Zara")).doubleValue();
      hm.put("Zara", new Double(balance + 1000));
      System.out.println("Zara's new balance: " + hm.get("Zara"));
   }
}
~                                          
