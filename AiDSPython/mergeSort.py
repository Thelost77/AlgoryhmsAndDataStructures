def mergeSort(firstIndex, lastIndex):
    if(firstIndex < lastIndex):
        mediumIndex = (lastIndex + firstIndex) / 2
        mergeSort(firstIndex, mediumIndex)
        mergeSort(mediumIndex + 1, lastIndex)
        bitMerge(firstIndex, mediumIndex, lastIndex)

def bitMerge():
    