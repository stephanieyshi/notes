import java.util.Stack;
import java.util.LinkedList;

public class DFS {
    LinkedList<Integer>[] adj;

    public DFS(LinkedList<Integer>[] adj) {
        this.adj = adj;
    }

    void search(int source) {
        boolean[] visited = new boolean[adj.length];

        // use a stack
        Stack<Integer> stack = new Stack<Integer>();

        stack.push(source);

        while (!stack.empty()) {
            source = stack.pop();

            if (!visited[source]) {
                System.out.print(source + " ");
                visited[source] = true;
            }

            // push everythign in the adjacency list of source to the stack
            for (Integer i : adj[source]) {
                if (!visited[i]) {
                    stack.push(i);
                }
            }
        }

    }
}
