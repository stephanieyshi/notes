public class BST {

    boolean isValidBST() {
        return isValidBSTHelper(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    boolean isValidBSTHelper(Node node, int min, int max) {
        if (node == null) {
            return true;
        } else if (node.getValue() < min || node.getValue() > max) {
            return false;
        } else {
            return (isValidBSTHelper(node.left(), min, node.getValue()), isValidBSTHelper(node.right(), node.getValue(), max));
        }
    }

}
